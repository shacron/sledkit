from distutils.core import setup, Extension

def main():
  setup(
    name="psled",
    version="1.0.0",
    description="Sled emulator extension in python",
    author="sledKit project",
    author_email="",
    ext_modules=[Extension("psled", ["bindings/python/bind.c"])]
  )

if (__name__ == "__main__"):
  main()