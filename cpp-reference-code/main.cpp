/*
Example program to make the NAO6 say a desired phrase. The C++ SDK provides 
a lower-level interface than the Python SDK that requires more explicit 
management of brokers and proxies. This gives developers more control 
over the initialization and shutdown process, but it also requires 
them to handle these details manually. If this seems too annoying to 
deal with I would suggest switching to the Python SDK.
*/

#include <iostream>
#include <alerror/alerror.h>
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

    // The desired phrase to be said.
    const std::string phraseToSay = "You have the c plus plus SDK working perfectly!";

    try
    {
        // Create your own broker
        boost::shared_ptr<AL::ALBroker> broker;
        try
        {
            broker = AL::ALBroker::createBroker(
                "myBroker",   // broker name
                "0.0.0.0",    // broker IP
                0,            // broker port (0 for default)
                argv[1],      // NAO IP
                9559          // NAO port
            );
        }
        catch(...)
        {
            std::cerr << "Failed to connect broker." << std::endl;
            return 1;
        }

        // Obtain the proxy using the broker
        AL::ALProxy proxy(broker, "ALTextToSpeech", 0, 0);

        // Call the say method on the proxy
        proxy.callVoid("say", phraseToSay);

        // Shutdown the broker after usage
        broker->shutdown();
    }
    catch (const AL::ALError& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
