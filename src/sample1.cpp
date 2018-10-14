
#include "../include/umbrella.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "time.h"

using namespace std;

//int main(int argc, char* argv[])
int main()
{
    //https://api.meteomatics.com/2018-10-13T12:15:00ZPT30M:PT5M/precip_15min:mm/50,10/json?model=mix
    const string METEOMATICS_USER = "jersey-hackathon05";
    const string METEOMATICS_PASSWORD = "hrB4KtC585tS";

    std::string msg;            // returns http error messages, should there be one -- empty otherwise
    bool success = true;

    cout << "**********" << std::endl;
    //cout << "> Initialising client..." << std::endl;

    MeteomaticsApiClient api_client(METEOMATICS_USER, METEOMATICS_PASSWORD, 300);

    std::vector<std::string> parameters = {"prob_precip_1h:p"};

    int year = api_client.getCurrentYear();
    int month = api_client.getCurrentMonth();
    int day = api_client.getCurrentDay();
 
    time_t theTime = time(NULL);
    struct tm *uTime = gmtime(&theTime);

    int hour=uTime->tm_hour;
    int min=uTime->tm_min;

    std::string startTime = api_client.getIsoTimeStr(year, month, day, hour, min, 0);
    std::string stopTime = api_client.getIsoTimeStr(year, month, day, hour + 1, min, 0);
    cout << startTime << " to " << stopTime << std::endl;

    std::vector<std::string> returnTimes;

    Matrix resultMatrix;                                  // resultMatrix [time][parameter]

    double lat = 49.1824757;
    double lon = -2.1034523;

    std::vector<std::string> optionals = {"model=mix"};

    //
    // Single Point  (single coordinate, single time, one or more parameters)
    //
    std::vector<std::string> resultVector;

    while(success)
    {
    double rainRisk = 0.0;
    bool quiteWindy = false;
    bool tooWindy = false;

    success = api_client.getTimeSeries(startTime, stopTime, "T5M", parameters, lat, lon, resultMatrix, resultVector, msg, optionals);

    if (success)
    {
        double max_chance = 0;

        cout << "**********" << std::endl;
        for(size_t i=0; i<resultMatrix.size(); ++i)
        {
           // cout << i << std::endl;

            vector<double> v = resultMatrix[i];
            for(size_t j=0;j<v.size();++j)
            {
                //cout << v[j] << "%" << endl;

                max_chance = v[j] > max_chance ? v[j] : max_chance;
            }

        }
            cout << "MAX:" << max_chance << "%" << endl;

            rainRisk = max_chance;
    }
    else
        std::cout << "Error msg = " << msg.substr(0,500) << "[...]" << std::endl << std::endl;

    // wind_speed_80m:kmh
    parameters = {"wind_speed_80m:kmh"};

    success = api_client.getTimeSeries(startTime, stopTime, "T5M", parameters, lat, lon, resultMatrix, resultVector, msg, optionals);

    if (success)
    {
        double max_speed = 0;

        cout << "**********" << std::endl;
        for(size_t i=0; i<resultMatrix.size(); ++i)
        {
           // cout << i << std::endl;

            vector<double> v = resultMatrix[i];
            for(size_t j=0;j<v.size();++j)
            {
                //cout << v[j] << "kmh" << endl;

                max_speed = v[j] > max_speed ? v[j] : max_speed;
            }

        }
            cout << "MAX:" << max_speed << "kmh" << endl;

            quiteWindy = max_speed >= 30;
            tooWindy = max_speed >= 41;
    }
    else
        std::cout << "Error msg = " << msg.substr(0,500) << "[...]" << std::endl << std::endl;

    // conclusion
    cout << "Next Hour: " << rainRisk << "% chance of rain, wind is " << (tooWindy? "TOO STRONG" : (quiteWindy ? "QUITE STRONG" : "")) << endl;

    std::this_thread::sleep_for(chrono::seconds(30));

    }
}