package(default_visibility=['//visibility:public'])

cc_library(
  name = 'pivot',
  srcs = ['pivot.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = [':pivot', '//visualization'],
  linkopts = ['-lm']
)

cc_library(
  name = 'disk_brake_visualization',
  srcs = ['disk_brake_visualization.cpp'],
  hdrs = ['disk_brake_visualization.h'],
  deps = [':pivot', '//visualization'],
  linkopts = ['-lm']
)

cc_binary(
  name = 'simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':pivot', '//solutions/pivot:controller_simple']
)

cc_binary(
  name = 'disk_brake',
  srcs = ['disk_brake.cpp'],
  deps = [':disk_brake_visualization', ':pivot', '//solutions/pivot:controller_brake']
)
