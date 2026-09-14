# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts
import random

# 1. 湖南省14个地级市/州
cities = [
    "长沙市", "株洲市", "湘潭市", "衡阳市",
    "邵阳市", "岳阳市", "常德市", "张家界市",
    "益阳市", "郴州市", "永州市", "怀化市",
    "娄底市", "湘西土家族苗族自治州",
]

# 2. 为每个市生成随机颜色
pieces = []
data = []
for city in cities:
    val = random.randint(1, 10000)
    data.append((city, val))
    pieces.append({"min": val, "max": val, "color": "#{:06x}".format(random.randint(0, 0xFFFFFF)), "label": city})

# 3. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh"))
    .add(
        "",
        data,
        "湖南",
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
c.render("hunanN.html")
print("湖南省地图已生成，请查看 hunan.html")
