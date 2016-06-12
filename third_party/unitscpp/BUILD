licenses(["permissive"])

cc_library(
  name = 'unitscpp',
  srcs = [],
  hdrs = [':generate_header'],
  visibility = ["//visibility:public"],
)

genrule(
  name = 'generate_header',
  srcs = ['units.cfg'],
  cmd = '$(location :gen) $(location :units.cfg) > $@',
  tools = [':gen'],
  outs = ['unitscpp.h']
)

py_binary(
  name = 'gen',
  srcs = ['gen.py'],
  default_python_version = "PY3"
)
