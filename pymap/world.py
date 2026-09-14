# 确保已安装：pip install pyecharts
from pyecharts.charts import Map
from pyecharts import options as opts

# 1. 准备分组数据 (国家, 数值)
# 这里用各大洲作为分组示例，你可以替换成任何你想要的分组逻辑

# 第一组：亚洲部分国家 (value: 30)
group_1 = [
    ("China", 90), ("Japan", 60), ("South Korea", 30),
    ("India", 10), ("Thailand", 70), ("Vietnam", 20)
]

# 第二组：欧洲部分国家 (value: 50)
group_2 = [
    ("Russia", 0), ("Germany", 20), ("France", 50),
    ("United Kingdom", 90), ("Italy", 40), ("Spain", 80)
]

# 第三组：美洲部分国家 (value: 70)
group_3 = [
    ("United States", 10), ("Canada", 50), ("Brazil", 70),
    ("Mexico", 9), ("Argentina", 30)
]

# 第四组：其他大洲国家 (value: 90)
group_4 = [
    ("Australia", 10), ("Egypt", 40), ("South Africa", 70),
    ("Nigeria", 90), ("Saudi Arabia", 20)
]

# 合并所有数据
data = group_1 + group_2 + group_3 + group_4

# 2. 创建全屏地图
c = (
    Map(init_opts=opts.InitOpts(width="100%", height="100vh"))
    .add(
        "",
        data,
        "world",  # 核心改动：地图类型从 "china" 变为 "world"
        label_opts=opts.LabelOpts(is_show=False), # 隐藏国家名
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(is_show=False),
        tooltip_opts=opts.TooltipOpts(is_show=False), # 隐藏鼠标悬停提示框
    )
)

# 3. 注入 CSS，去掉页面默认边距，实现真正全屏
c.add_js_funcs("""
    document.body.style.margin = '0';
    document.body.style.padding = '0';
    document.body.style.overflow = 'hidden';
""")

# 4. 生成文件
c.render("worldBlank.html")
print("世界地图已生成，请查看 worldBlank.html")
