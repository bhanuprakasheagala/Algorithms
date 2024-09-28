#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id;
    int deadline;
    int profit;
    Job(int _id, int _deadline, int _profit) : id(_id), deadline(_deadline), profit(_profit) {}
};

std::pair<int, std::vector<int>> jobSequencing(std::vector<Job>& jobs) {
    // Sort the array based on their profits in descending order
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
        return a.profit > b.profit;
    });

    // Find the maximum deadline
    int maxDeadline = 0;
    for(const Job& job : jobs) {
        maxDeadline = std::max(maxDeadline, job.deadline);
    }

    // Initialize the timeslots array, index 0 to maxDeadline. Initally all slots are free.
    std::vector<int> timeSlots(maxDeadline+1, -1);

    // Schedule the jobs
    int totalProfit = 0;
    std::vector<int> scheduledJobs;
    for(const Job& job : jobs) {
        // Find the latest possible time slot available before the deadline
        for(int i = job.deadline; i > 0; --i) {
            if(timeSlots[i] == -1) {
                timeSlots[i] = job.id;
                totalProfit += job.profit;
                scheduledJobs.push_back(job.id);
                
                break;
            }
        }
    }

    return {totalProfit, scheduledJobs};
}

int main()
{
    std::vector<Job> jobs = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    auto res = jobSequencing(jobs);
    std::cout << "Maximum Profit: " << res.first << '\n';
    std::cout << "Scheduled jobs: ";
    for(int jobId : res.second) {
        std::cout << jobId << " ";
    }
    std::cout << '\n';

    return 0;
}