#include <iostream>
#include <queue>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

struct Job {

    int jobID = 0;
    int arrivalTime = 0;
    int processTime = 0;

};

int getNextCPU(Job cpuArray[])
{
    cout << "Getting next CPU" << endl;
    for (int i = 0; i < 4; i++) {
        if (cpuArray[i].processTime == 0) {
            cout << "returning i: " << i << endl;
            return i;
        }
    }
    cout << "returning -1" << endl;
    return -1;
}

int main() {

    //Set Job Time
    const int numOfJobs = 6;
    Job jobArray[numOfJobs + 1];

    //Set Job Info
    int setJobProcessTime = 0;

    //Set rand seed
    srand(time(NULL));
    for (int i = 1; i <= numOfJobs; i++)
    {
        //Loop through jobArray, setting arrival time to clock and process time between 1-10 units.
        setJobProcessTime = rand() % 10 + 1;

        jobArray[i] = { i, i, setJobProcessTime };

    }

    /* BEGIN Initialize Variables */
    int jobStartTime[numOfJobs + 1];
    int jobWaitingTime[numOfJobs + 1];
    int jobTurnoverTime[numOfJobs + 1];

    double lengthOfJob_AVG = 0;
    int lengthOfJob_MIN = 100000000;
    int lengthOfJob_MAX = 0;

    queue<Job>JOBQUEUE;
    Job cpuArray[4];
    int currentJob = 1;
    int numOfCompletedJobs = 0;

    int queueLength_MAX = 0;
    int queueLength_MAX_TIME = 0;
    int numOfJobsEnqueued = 0;

    int busyTimeCPU[4] = { 0 }, idleTimeCPU[4] = { 0 }, jobsServed[4] = { 0 };
    /* END Initialize Variables */

    //Total Clock time Must be between 1 and 600, inclusively.
    for (int timer = 0; timer <= 600 && numOfCompletedJobs < numOfJobs; timer++)
    {
        //Job Arrival
        while (jobArray[currentJob].arrivalTime == timer)
        {
            cout << "First While Loop" << endl;
            int cpuIndex = getNextCPU(cpuArray);
            if (cpuIndex == -1)
            {
                JOBQUEUE.push(jobArray[currentJob]);
                numOfJobsEnqueued++;
            }
            else
            {
                cpuArray[cpuIndex] = jobArray[currentJob];
                jobsServed[cpuIndex]++;
                jobStartTime[currentJob] = timer;
            }

            //Calculate Job Info
            lengthOfJob_AVG += jobArray[currentJob].processTime;
            lengthOfJob_MIN = min(lengthOfJob_MIN, jobArray[currentJob].processTime);
            lengthOfJob_MAX = max(lengthOfJob_MAX, jobArray[currentJob].processTime);
            currentJob++;
        }
        //Push Job to Queue
        int cpuIndex = getNextCPU(cpuArray);
        while (!JOBQUEUE.empty() && cpuIndex != -1)
        {
            cout << "2nd While Loop is running" << endl;
            cpuArray[cpuIndex] = JOBQUEUE.front();
            cout << "cpuArray has run" << endl;

            //Calculate #of Jobs Served
            jobsServed[cpuIndex]++;
            cout << "jobsserved has run" << endl;

            jobStartTime[JOBQUEUE.front().jobID] = timer;
            cout << "jobstarttime has run" << endl;
            JOBQUEUE.pop();
            cpuIndex = getNextCPU(cpuArray);
            cout << "2nd while loop is ending" << endl;
        }

        //Calculate BusyTime and idleTime for CPUs
        for (int i = 0; i < 4; i++)
        {
            if (cpuArray[i].processTime > 0)
            {
                busyTimeCPU[i]++;
            }
            else
            {
                idleTimeCPU[i]++;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (cpuArray[i].processTime > 0)
            {
                cpuArray[i].processTime--;

                if (cpuArray[i].processTime == 0)
                {
                    numOfCompletedJobs++;
                }
            }
        }

        //Calculate queue max size and time
        if (queueLength_MAX < JOBQUEUE.size())
        {
            queueLength_MAX = JOBQUEUE.size();
            queueLength_MAX_TIME = timer;
        }

    }

    for (int i = 1; i <= numOfJobs; i++)
    {
        // calculate the waiting time
        int id = jobArray[i].jobID;

        jobWaitingTime[i] = jobStartTime[id] - jobArray[i].arrivalTime;

        // calculate the turnaround time
        jobTurnoverTime[i] = jobArray[i].processTime + jobWaitingTime[i];
    }

    cout << "Job               Queue Time         Average Turnover" << endl;
    for (int i = 1; i <= numOfJobs; i++)
    {
        cout << jobArray[i].jobID << "		  " << jobWaitingTime[i] << "	  	     " << jobTurnoverTime[i] << endl;
    }

    double turnover_AVG = 0;
    double queue_AVG_TIME_IN = 0;

    // calculate the average waiting and turnaround
    for (int i = 1; i <= numOfJobs; i++)
    {
        turnover_AVG += jobTurnoverTime[i];
        queue_AVG_TIME_IN += jobWaitingTime[i];

    }

    // calculate the average time
    turnover_AVG /= numOfJobs;
    lengthOfJob_AVG /= numOfJobs;


    cout << endl;

    // output the result
    cout << "The Average Turnover time: " << turnover_AVG << endl;
    cout << "The total Waiting time: " << queue_AVG_TIME_IN << endl;
    cout << "The Average Waiting time: " << queue_AVG_TIME_IN / numOfJobs << endl;
    cout << "Min Job Length: " << lengthOfJob_MIN << "   Max Job Length: " << lengthOfJob_MAX << "  Average Job Length: " << lengthOfJob_AVG << endl;

    cout << endl;
    cout << "Maximum queue length: " << queueLength_MAX << endl;
    cout << "Time the queue was at its max length: " << queueLength_MAX_TIME << endl;
    cout << "Total number of jobs waited in queue: " << numOfJobsEnqueued << endl;
    cout << "The percentage of jobs waited to total served: " << 1.0 * numOfJobsEnqueued / numOfJobs << endl;

    cout << endl;

    // CPU Info Calculations
    cout << "CPU       |Busy     |Idle       |Served" << endl;
    cout << "----------|---------|-----------|------" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << "         " << "|" << busyTimeCPU[i] << "	    " << "|" << idleTimeCPU[i] << "		" << "|" << jobsServed[i] << endl;
    }

    return 0;
}