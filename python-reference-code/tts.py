'''
Example program to make the NAO6 say a desired phrase. We first create
a text to speech proxy as well as an animated speech proxy. Note 
that in the Python SDK, the ALBroker instance is automatically created 
when you instantiate a proxy for the first time. 
'''

from naoqi import ALProxy, ALBroker
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <NAO_IP>")
    exit(1)

nao_IP = sys.argv[1]
nao_port = 9559

tts = ALProxy("ALTextToSpeech", nao_IP, nao_port) # creates a proxy for text to speech
tts.setVolume(1.0) # define volume of the robot
animatedSpeech = ALProxy("ALAnimatedSpeech", nao_IP, nao_port) # animated speech extends tts to enhance speech

try:
    pythonBroker = ALBroker("pythonBroker", "0.0.0.0", 0, nao_IP, nao_port) # broker connection: essential for communicating between the module and the NAOqi runtime
    message = "You have the python SDK working perfectly!"
    animatedSpeech.say(message)
    # tts.say(message) # This works as well, run each option and see the difference

except RuntimeError:
    print("Error initializing broker!")
    exit(1)