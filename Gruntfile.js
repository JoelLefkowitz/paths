const glob = require("glob");
const { simple } = require("quick-grunt");

const srcs = glob.sync("src/**/*.{hpp,cpp}").join(" ");

module.exports = simple(
  {
    clean: {},
    copy: {},
    exec: {
      cppcheck: "cppcheck --enable=style,performance,portability src",
      cspell: 'npx cspell ".*" "*" "**/*"',
      remark: "npx remark -r .remarkrc --ignore-path .gitignore . .github",
      cfmt: `clang-format -i -style=file ${srcs} --verbose`,
      doxygen: "doxygen",
    },
  },
  [
    {
      name: "lint",
      description: "Lint the source code.",
      exec: ["cspell", "cppcheck", "remark"],
    },
    {
      name: "format",
      description: "Format the source code.",
      exec: ["cfmt"],
    },
    {
      name: "docs",
      description: "Generate documentation.",
      exec: ["doxygen"],
    },
  ]
);
