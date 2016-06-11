package(default_visibility=['//visibility:public'])

cc_library(
  name = 'visualization',
  hdrs = ['visualization.h'],
  srcs = ['visualization.cpp'],
  linkopts = [
    '-lsfml-system',
    '-lsfml-window',
    '-lsfml-graphics'
  ],
  data = ['font.ttf']
)

cc_binary(
  name = 'example_visualization',
  srcs = ['visualization_example.cpp'],
  deps = [':visualization', '//third_party/unitscpp'],
  linkopts = ['-lm']
)
