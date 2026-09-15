def create_china_map():
    html_content = r"""<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>中国地图</title>
    <!-- 关键修改：使用 ECharts 4.9.0，该版本内置中国地图数据 -->
    <script src="https://cdn.jsdelivr.net/npm/echarts@4.9.0/dist/echarts.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/echarts@4.9.0/map/js/china.js"></script>
    <style>
        * { margin: 0; padding: 0; }
        #main { width: 100vw; height: 100vh; }
    </style>
</head>
<body>
    <div id="main"></div>
    <script>
        var chart = echarts.init(document.getElementById('main'));

        var data = [
            {name:'湖南',value:25},{name:'湖北',value:25},{name:'广东',value:25},{name:'广西',value:25},
            {name:'河南',value:25},{name:'河北',value:25},{name:'山东',value:25},{name:'山西',value:25},
            
            {name:'四川',value:50},{name:'西藏',value:50},{name:'云南',value:50},{name:'贵州',value:50},
            {name:'内蒙古',value:50},{name:'吉林',value:50},{name:'安徽',value:50},
            
            {name:'北京',value:75},{name:'天津',value:75},{name:'上海',value:75},{name:'重庆',value:75},
            {name:'宁夏',value:100},{name:'新疆',value:100},{name:'青海',value:75},{name:'甘肃',value:75},{name:'陕西',value:75},
            
            {name:'江苏',value:100},{name:'江西',value:100},{name:'浙江',value:100},{name:'黑龙江',value:100},
            {name:'辽宁',value:100},{name:'福建',value:100},{name:'海南',value:100},{name:'台湾',value:100}
        ];

        var option = {
            title: {
                text: '中国地图',
                subtext: '两湖两广两河山\n川藏云贵蒙吉安\n四市二区青甘陕\n五江二宁福海湾',
                left: 20,
                top: 20,
                textStyle: { fontSize: 20, fontWeight: 'bold' },
                subtextStyle: { fontSize: 14, lineHeight: 22 }
            },
            tooltip: { trigger: 'item' },
            toolbox: {
                show: true,
                right: 20,
                top: 'center',
                orient: 'vertical',
                feature: {
                    saveAsImage: { show: true, title: '保存为图片' },
                    restore: { show: true, title: '重置' },
                    dataView: { show: true, title: '数据视图' }
                }
            },
            visualMap: {
                min: 0,
                max: 100,
                left: 20,
                bottom: 40,
                text: ['高', '低'],
                calculable: true,
                inRange: {
                    color: ['#2b88b9', '#f2d536', '#df6a5d']
                }
            },
            series: [{
                name: '省份',
                type: 'map',
                mapType: 'china',
                roam: true,
                label: {
                    show: true,
                    fontSize: 11,
                    color: '#000'
                },
                itemStyle: {
                    areaColor: '#e0e0e0',
                    borderColor: '#888'
                },
                emphasis: {
                    label: { show: true, fontSize: 13, fontWeight: 'bold' },
                    itemStyle: { areaColor: '#ffd700' }
                },
                data: data
            }]
        };

        chart.setOption(option);
        window.addEventListener('resize', function() { chart.resize(); });
    </script>
</body>
</html>"""

    with open("render.html", "w", encoding="utf-8") as f:
        f.write(html_content)
    print("生成成功！请在同目录下打开 render.html 查看效果。")

if __name__ == "__main__":
    create_china_map()
