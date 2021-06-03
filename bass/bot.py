import logging
import requests
import datetime
from config import weather_token
from aiogram import Bot, Dispatcher, executor, types
import config
from sqllighter import SQLighter

logging.basicConfig(level=logging.INFO)
bot = Bot(token=config.bot_token, parse_mode="HTML")
dp = Dispatcher(bot)
db = SQLighter('db.db')


@dp.message_handler(commands=['subscribe'])
async def subscribe(message: types.Message):
    if not db.subscriber_exists(message.from_user.id):
        db.add_subscriber(message.from_user.id)
    else:
        db.update_subscription(message.from_user.id, True)
    await message.answer("Спасибо за подписку на наш Telegramm канал! С нами будет весело!")


@dp.message_handler(commands=['unsubscribe'])
async def subscribe(message: types.Message):
    if not db.subscriber_exists(message.from_user.id):
        db.add_subscriber(message.from_user.id, False)
        await message.answer(
            "Очень жаль, что вы отписались, надеемся, что вы сообщите создателю о вашей проблеме: https://vk.com/augusstt")
    else:
        ()


@dp.message_handler(commands=['start'])
async def subscribe(message: types.Message):
    await message.reply("Привет, что ты именно хочешь?")


@dp.message_handler(commands=['weather'])
async def start_command(message: types.Message):
    await message.reply("Напиши мне название города, в котором хочешь узнать погоду")


@dp.message_handler()
async def start_command(message: types.Message):
    code_to_smile = {"Clear": "Ясно \U00002600",
                     "Clouds": "Облачно \U00002601",
                     "Rain": "Дождь \U00002614",
                     "Drizzle": "Дождь \U00002614",
                     "Thunderstorm": "Гроза \U000026A1",
                     "Snow": "Снег \U0001F328",
                     "Mist": "Туман \U0001F32B"}
    try:
        r = requests.get(
            f"http://api.openweathermap.org/data/2.5/weather?q={message.text}&appid={weather_token}&units=metric")
        data = r.json()
        city = data["name"]
        cur_weather = data["main"]["temp"]
        wind = data["wind"]["speed"]
        sunrise_timestamp = datetime.datetime.fromtimestamp(data["sys"]["sunrise"])
        sunset_timestamp = datetime.datetime.fromtimestamp(data["sys"]["sunset"])
        length_of_the_day = datetime.datetime.fromtimestamp(data["sys"]["sunrise"]) - datetime.datetime.fromtimestamp(
            data["sys"]["sunset"])
        weather_description = data["weather"][0]["main"]
        if weather_description in code_to_smile:
            wd = code_to_smile[weather_description]
        await message.reply(f"***{datetime.datetime.now().strftime('%Y-%m-%d %H:%M')}***\n"
                            f"Погода в городе: {city}\n Температура: {cur_weather}C° {wd}\n"
                            f"Ветер: {wind}\n"
                            f"Время рассвета: {sunrise_timestamp}\nВремя заката: {sunset_timestamp}\n"
                            f"Продолжительность дня: {length_of_the_day}")


    except:
        await message.reply("\U00002620 Проверьте название города \U00002620")
        return 0


if __name__ == '__main__':
    executor.start_polling(dp, skip_updates=True)
