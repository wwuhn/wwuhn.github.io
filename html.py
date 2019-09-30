from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.header import Header
import smtplib # SMTP即简单邮件传输协议

# 1 邮件信息
email_from = "wwuhnwu@163.com"
sender = email_from
email_to = ["wwuhnwu@163.com","2283517648@qq.com"]
receiver = ",".join(email_to)
password = "63695694Wu"
email_subject = "website html file backup"
body = """
Dear all,
Attached please find!
"""
annex_path = "D:\\Users\\wwuhnwu01\\Desktop\\websitehtml.rar"
annex_name = "website.rar"

# 2 生成邮件（email模块）
message = MIMEMultipart()
message.attach(MIMEText(body,'plain','utf-8'))
message['From'] = Header(sender,'utf-8')
message['To'] = Header(receiver,'utf-8')
message['Subject'] = Header(email_subject,'utf-8')
att1 = MIMEText(open(annex_path, 'rb').read(), 'base64', 'utf-8')
att1["Content-Type"] = 'application/octet-stream'
att1["Content-Disposition"] = 'attachment; filename=' + annex_name
message.attach(att1)
# 3 发送邮件（smtplib模块）
try:
    smtp = smtplib.SMTP_SSL("smtp.163.com",465)
    smtp.login(email_from,password)
    print("login successfully!")
    smtp.sendmail(email_from,email_to,message.as_string())
    print("sent successfully!")
    smtp.quit
except Exception:
    print(traceback.print_exc())
    print("sending failed!")
