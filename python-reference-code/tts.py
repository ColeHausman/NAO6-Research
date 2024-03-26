'''
Example program to make the NAO6 say a desired phrase. The naoqi framework 
abstracts away low level hardware interactions through the use of proxies
which are used extensively when programming with naoqi. Proxies support
event handling which is critical for more complex executions
'''

from naoqi import ALProxy, ALBroker

nao_IP = "nao.local" # nao.local == robot ip
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