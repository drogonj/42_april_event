import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

if __name__ == "__main__":
    #Initialisation variables
    sender = "unepetitadressemaildetesttressympa@gmx.com"
    password = "smtptest42"
    receiver = "obsitrix@gmail.com"
    smtp_server = "smtp.gmx.com"
    smtp_port = 587

    #Initialisaion MIME (Multipurpose Internet Mail Extensions)
    msg = MIMEMultipart()
    msg['From'] = sender
    msg['To'] = receiver
    msg['Subject'] = "WOUHOUUUUU"
    msg.attach(MIMEText("CA FONCTIONNE!!!!!!!", 'plain'))

    #Creation de la piece jointe
    try:
        file = open("example.txt", 'rb')
        tosendfile = MIMEBase('application', 'octet-stream')
        tosendfile.set_payload(file.read())
        encoders.encode_base64(tosendfile)
        tosendfile.add_header('Content-Disposition', 'attachment; filename=example.txt')
        msg.attach(tosendfile)
    except:
        print("Can't add file")
        exit(1);


    #Creation de la connexion SMTP
    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(sender, password)
        server.sendmail(sender, receiver, msg.as_string())
        print("Email sent successfully!")
    except:
        print("An error occurred")
