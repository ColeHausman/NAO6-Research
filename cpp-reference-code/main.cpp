#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/altexttospeechproxy.h>
#include <alcommon/albroker.h>
#include <alcommon/albrokermanager.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong number of arguments!" << std::endl;
        std::cerr << "Usage: ./main NAO_IP" << std::endl;
        return 1;
    }

    /** The desired phrase to be said. */
    const std::string phraseToSay = "You have the cpp SDK working perfectly!";

    try
    {
        // Establish a connection to the NAOqi runtime using ALBroker
        AL::ALBroker::createBroker("myBroker", "0.0.0.0", 0, argv[1], 9559);
        AL::ALTextToSpeechProxy tts("myBroker", 9559); // create a proxy for tts
        tts.say(phraseToSay);
        AL::ALBrokerManager::getInstance()->killAllBroker(); // Shutdown the broker after usage
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
