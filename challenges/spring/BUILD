package(default_visibility=['//visibility:public'])

cc_library(
  name = 'spring',
  hdrs = ['spring.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = ['//visualization', ':spring']
)

cc_binary(
  name = 'challenge_simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':spring', '//solutions/spring:controller_simple']
)
