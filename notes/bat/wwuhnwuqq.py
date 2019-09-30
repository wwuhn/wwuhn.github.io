from poplib import POP3
import re,email,email.header
def decode_email_content(msg_src,names):
    msg = email.message_from_bytes(msg_src)
    result = {}
    for name in names:
        content = msg.get(name)
        info = email.header.decode_header(content)
        if info[0][1]:
            if info[0][1].find('unknow-') == -1:
                result[name] = info[0][0].decode(info[0][1])
            else:
                try:
                    result[name] = info[0][0].decode('gbk')
                except:
                    result[name] = info[0][0].decode('utf-8')
        else:
            result[name] = info[0][0]
    return result
if __name__ == "__main__":
    pp = POP3("pop.qq.com")
    pp.user("2283517648@qq.com")
    pp.pass_("63695694Wu01")
    total,totalnum = pp.stat()
    print(total,totalnum)
    n = 10
    if total<10:
        n = total
    for i in range(total-n,total):
        hinfo,msgs,octet = pp.top(i+1,0)
        b = b''
        for msg in msgs:
            b += msg+b'\n'
        items = decode_email_content(b,['subject','from'])
        print(items['subject'],'\nFrom:',items['from'])
        print()
    pp.close()
