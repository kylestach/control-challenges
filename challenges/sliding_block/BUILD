package(default_visibility=['//visibility:public'])

cc_library(
  name = 'sliding_block',
  hdrs = ['sliding_block.h'],
  deps = ['//third_party/unitscpp']
)

cc_library(
  name = 'visualization',
  srcs = ['visualization.cpp'],
  hdrs = ['visualization.h'],
  deps = ['//visualization', ':sliding_block']
)

cc_binary(
  name = 'challenge_simple',
  srcs = ['simple.cpp'],
  deps = [':visualization', ':sliding_block', '//solutions/sliding_block:controller_simple']
)

cc_binary(
  name = 'challenge_no_friction',
  srcs = ['no_friction.cpp'],
  deps = [':visualization', ':sliding_block', '//solutions/sliding_block:controller_no_friction']
)

cc_binary(
  name = 'challenge_goal',
  srcs = ['goal.cpp'],
  deps = [':visualization', ':sliding_block', '//solutions/sliding_block:controller_goal']
)
