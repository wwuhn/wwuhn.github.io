# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts

# 1. 准备分组数据

group_1 = [
    ("湖南", 30), ("湖北", 30), ("广东", 30), ("广西", 30),
    ("河南", 30), ("河北", 30), ("山东", 30), ("山西", 30)
]

group_2 = [
    ("四川", 50), ("西藏", 50), ("云南", 50), ("贵州", 50),
    ("内蒙古", 50), ("吉林", 50), ("安徽", 50)
]

group_3 = [
    ("北京", 70), ("上海", 70), ("天津", 70), ("重庆", 70),
    ("香港", 70), ("澳门", 70), ("青海", 70), ("甘肃", 70), ("陕西", 70)
]

group_4 = [
    ("江苏", 90), ("浙江", 90), ("江西", 90), ("黑龙江", 90), ("新疆", 90),
    ("辽宁", 90), ("宁夏", 90), ("福建", 90), ("海南", 90), ("台湾", 90)
]

data = group_1 + group_2 + group_3 + group_4

# 2. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh"))
    .add(
        "",
        data,
        "china",
        label_opts=opts.LabelOpts(is_show=False),       # 隐藏省名
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(is_show=False),
        tooltip_opts=opts.TooltipOpts(is_show=False),   # 隐藏鼠标悬停提示框
    )
)

# 3. 注入 CSS，去掉页面默认边距，实现真正全屏
c.add_js_funcs("""
    document.body.style.margin = '0';
    document.body.style.padding = '0';
    document.body.style.overflow = 'hidden';
""")

# 4. 生成文件
c.render("cnBlank.html")
print("地图已生成，请查看 render.html")
