import imaplib, serial #import modules

sercomm = serial.Serial('COM3', 9600) #serial object
obj = imaplib.IMAP4_SSL('imap.gmail.com') #create imap object, set to gmail
obj.login('burakalbeni@gmail.com', '********') #credentials

#runs continuously 
while 1: 
 obj.select() #refresh 
 val = len(obj.search(None, 'UnSeen')[1][0].split()) #generate a value of 1 or 0
 print ("The val is: %d\n" %val) #print value to monitor
 if(val==0):#the case where we get the value '0' python recognizes it as a boolean false which is not intended 
  sercomm.write(b'0')
 sercomm.write(val) #write value to serial port
#ser.close() 

       
