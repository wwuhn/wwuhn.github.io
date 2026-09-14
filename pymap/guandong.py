# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts
import random

# 1. 广东省21个地级市
cities = [
    "广州市", "深圳市", "珠海市", "汕头市", "佛山市",
    "韶关市", "湛江市", "肇庆市", "江门市", "茂名市",
    "惠州市", "梅州市", "汕尾市", "河源市", "阳江市",
    "清远市", "东莞市", "中山市", "潮州市", "揭阳市",
    "云浮市",
]

# 2. 为每个市生成随机颜色
def random_color():
    return "#{:06x}".format(random.randint(0, 0xFFFFFF))

pieces = []
data = []
for city in cities:
    val = random.randint(1, 10000)
    data.append((city, val))
    pieces.append({"min": val, "max": val, "color": random_color(), "label": city})

# 3. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh"))
    .add(
        "",
        data,
        "广东",
        label_opts=opts.LabelOpts(is_show=True),
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(
            is_show=False,
            is_piecewise=True,
            pieces=pieces,
        ),
        tooltip_opts=opts.TooltipOpts(is_show=False),
    )
)

# 4. 全屏处理
c.add_js_funcs("""
    document.body.style.margin = '0';
    document.body.style.padding = '0';
    document.body.style.overflow = 'hidden';
""")

# 5. 生成文件
c.render("guangdongN.html")
print("广东省地图已生成，请查看 guangdongN.html")
