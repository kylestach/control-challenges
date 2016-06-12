package(default_visibility=['//visibility:public'])

cc_library(
  name = 'flywheel',
  srcs = ['flywheel.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = [':flywheel', '//visualization']
)

cc_binary(
  name = 'simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':flywheel', '//solutions/flywheel:controller_simple']
)
