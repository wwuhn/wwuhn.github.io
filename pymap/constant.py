# pip install echarts-countries-pypkg
# pip install echarts-china-provinces-pypkg
# pip install echarts-china-cities-pypkg
# pip install echarts-china-counties-pypkg
# pip install echarts-china-misc-pypkg
from __future__ import unicode_literals

from pyecharts import Map
import pyecharts.constants as constants

constants.CITY_NAME_PINYIN_MAP['南澳县']='nanao'
#constants.ENVIRONMENT_PLUGIN_TYPE['南澳县']='nanao'

value = []
attr = []
map = Map("南澳县地图示例", width=1200, height=600)
map.add("", attr, value, maptype='南澳县', is_visualmap=True, visual_text_color='#000')
map.render()
