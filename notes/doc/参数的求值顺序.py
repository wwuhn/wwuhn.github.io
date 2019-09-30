class printTable(object):
    def _init_(self):
        print(u'开始打印9*9的乘法表格')
        self.print99()
    def print99(self):
        for i in xrange(1,10):
            for j in xrange(1,i+1):
                print("%dX%d=%2s " %(j,i,i*j))
                print("\n")

if _name_ == '_main_':
    pt = printTable()
