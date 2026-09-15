def create_china_map():
    html_content = r"""<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>中国地图</title>
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
            {name:'吉林',value:50},{name:'安徽',value:50},
            {name:'北京',value:75},{name:'天津',value:75},{name:'上海',value:75},{name:'重庆',value:75},
            {name:'内蒙古',value:75},
            {name:'青海',value:75},{name:'甘肃',value:75},{name:'陕西',value:75},
            {name:'江苏',value:100},{name:'江西',value:100},{name:'浙江',value:100},{name:'黑龙江',value:100},
            {name:'宁夏',value:100},{name:'新疆',value:100},
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
                    itemStyle: {
                        areaColor: '#ffffff',
                        borderColor: '#333'
                    }
                },
                data: data,
                markPoint: {
                    symbol: 'circle',
                    symbolSize: 6,
                    itemStyle: {
                        color: '#d93a3a'
                    },
                    label: {
                        show: false
                    },
                    data: [
                        {name:'长沙',coord:[112.94,28.23]},
                        {name:'武汉',coord:[114.31,30.59]},
                        {name:'广州',coord:[113.26,23.13]},
                        {name:'南宁',coord:[108.32,22.82]},
                        {name:'郑州',coord:[113.65,34.76]},
                        {name:'石家庄',coord:[114.48,38.03]},
                        {name:'济南',coord:[117.00,36.65]},
                        {name:'太原',coord:[112.55,37.87]},
                        {name:'成都',coord:[104.07,30.67]},
                        {name:'拉萨',coord:[91.13,29.66]},
                        {name:'昆明',coord:[102.73,25.04]},
                        {name:'贵阳',coord:[106.71,26.57]},
                        {name:'呼和浩特',coord:[111.65,40.82]},
                        {name:'长春',coord:[125.35,43.88]},
                        {name:'合肥',coord:[117.27,31.86]},
                        {name:'北京',coord:[116.46,39.92]},
                        {name:'天津',coord:[117.20,39.13]},
                        {name:'上海',coord:[121.48,31.22]},
                        {name:'重庆',coord:[106.54,29.59]},
                        {name:'银川',coord:[106.27,38.47]},
                        {name:'乌鲁木齐',coord:[87.68,43.77]},
                        {name:'西宁',coord:[101.74,36.56]},
                        {name:'兰州',coord:[103.83,36.06]},
                        {name:'西安',coord:[108.95,34.27]},
                        {name:'南京',coord:[118.78,32.04]},
                        {name:'南昌',coord:[115.89,28.68]},
                        {name:'杭州',coord:[120.19,30.26]},
                        {name:'哈尔滨',coord:[126.63,45.75]},
                        {name:'沈阳',coord:[123.38,41.80]},
                        {name:'福州',coord:[119.30,26.08]},
                        {name:'海口',coord:[110.35,20.02]},
                        {name:'台北',coord:[121.50,25.03]}
                    ]
                }
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
