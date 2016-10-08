package(default_visibility=['//visibility:public'])

cc_library(
  name = 'elevator',
  srcs = ['elevator.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = [':elevator', '//visualization']
)

cc_binary(
  name = 'simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':elevator', '//solutions/elevator:controller_simple']
)
