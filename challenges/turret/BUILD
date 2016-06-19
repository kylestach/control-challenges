package(default_visibility=['//visibility:public'])

cc_library(
  name = 'turret',
  srcs = ['turret.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = [':turret', '//visualization'],
  linkopts = ['-lm']
)

cc_binary(
  name = 'simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':turret', '//solutions/turret:controller_simple']
)

cc_binary(
  name = 'moving_goal',
  srcs = ['moving_goal.cpp'],
  deps = [':visualization', ':turret', '//solutions/turret:controller_follow']
)
