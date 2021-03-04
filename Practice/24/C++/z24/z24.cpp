json joutput;
for (auto& pair : users) {
    joutput.push_back({
        {
            "userId",
            pair.first
        },
        {
            "task_completed",
            pair.second
        }
        });
}

std::ofstream output("out.json");
output << std::setw(2) << joutput << std::endl;
output.close();
}