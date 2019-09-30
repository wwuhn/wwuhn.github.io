import smtplib
from email.mime.text import MIMEText
from email.header import Header
# 发送邮箱服务器
smtpserver = 'smtp.163.com'
# 发送邮箱用户/密码
user = 'wwuhnwu@163.com'
password = '63695694Wu'
# 发送邮箱
sender = 'wwuhnwu@163.com'
# 接收邮箱
receiver = 'wwuhnwu@163.com'
# 发送邮件主题
subject = 'Python email test'
# 编写HTML类型的邮件正文
msg = MIMEText('<html><h4>你好！</h4><p>这是一封通过py发送的邮件！</html>','html','utf-8')
msg['Subject'] = Header(subject, 'utf-8')
# 连接发送邮件
smtp = smtplib.SMTP()
smtp.connect(smtpserver)
smtp.login(user, password)
smtp.sendmail(sender, receiver, msg.as_string())
print("mail send successfully!")
smtp.quit()
