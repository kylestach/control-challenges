package(default_visibility=['//visibility:public'])

cc_library(
  name = 'double_jointed',
  srcs = ['double_jointed.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = [':double_jointed', '//visualization'],
  linkopts = ['-lm']
)

cc_binary(
  name = 'simple',
  srcs = ['main.cpp'],
  deps = [':visualization', ':double_jointed']
)
