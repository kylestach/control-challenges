licenses(["permissive"])

cc_library(
  name = 'unitscpp',
  srcs = [],
  hdrs = [':units_autogen'],
  visibility = ["//visibility:public"],
)

genrule(
  name = 'units_autogen',
  srcs = ['units.cfg', 'gen.py'],
  cmd = 'python2 third_party/unitscpp/gen.py third_party/unitscpp/units.cfg > $@',
  outs = ['unitscpp.h']
)
