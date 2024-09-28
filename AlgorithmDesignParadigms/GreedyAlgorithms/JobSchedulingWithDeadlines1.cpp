/*
Given an array of jobs, where each job is associ- ated with its profit and deadline, find an ordering of
all jobs that maximizes the profit. A job generates a profit only if it is completed before the deadline.
*/
#include <iostream>
#include <vector>

struct Job {
    char jid;
    int jdeadline;
    int jprofit;
    Job() : jid('a'), jdeadline(0), jprofit(0) {}
};

bool profitBased(Job& j1, Job& j2) {

    if(j1.jprofit == j2.jprofit)
        return j1.jdeadline < j2.jdeadline;

    return j1.jprofit > j2.jprofit;
}

void jobSequencingWithDeadlines(std::vector<Job>& jobDetails, int n) {
    sort(jobDetails.begin(), jobDetails.end(), profitBased);

    int maxDeadline = 0;
    for(const auto& job : jobDetails) {
        maxDeadline = std::max(maxDeadline, job.jdeadline);
    }

    std::vector<bool> slot(maxDeadline, false);
    std::vector<char> result(maxDeadline, -1);

    for(int i=0; i<n; ++i) {
        for(int j = std::min(maxDeadline, jobDetails[i].jdeadline)-1; j>=0; --j) {
            if(!slot[j]) {
                result[j] = jobDetails[i].jid;
                slot[j] = true;
                break;
            }
        }
    }
    std::cout << "The sequence of jobs to maximize the profit: \n";
    for(int i=0; i<maxDeadline; ++i) {
        if(slot[i]) {
            std::cout << result[i] << " ";
        }
    }
    std::cout << '\n';
}

int main()
{
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;
    std::vector<Job> jobDetails(n);
    for(int i=0; i<n; ++i) {
        char id;
        int deadline, profit;
        std::cout << "Enter the id, deadline, and profit for job " << i+1 <<'\n';
        std::cin >> id;
        jobDetails[i].jid = id;
        std::cin >> deadline;
        jobDetails[i].jdeadline = deadline;
        std::cin >> profit;
        jobDetails[i].jprofit = profit;
    }

    jobSequencingWithDeadlines(jobDetails, n);

    return 0;
}