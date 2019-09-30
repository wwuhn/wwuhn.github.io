# pip install pyecharts

# pip install echarts-countries-pypkg

from pyecharts import Map
value = [68.6,1.117,66,78,33,80,190,53,49.6,88,22]
attr = ["湖南","广东","北京","上海","江苏",
       "四川","河南","甘肃","辽宁","山西","内蒙古"]
map = Map("中国地图",width=800,height=600)
map.add("概况",attr,value, maptype="china", is_visualmap=True,
        visual_text_color="#000",is_label_show=True) 
map.render()
# http://pyecharts.org/#/zh-cn/prepare
# C:\Python\Lib\site-packages
