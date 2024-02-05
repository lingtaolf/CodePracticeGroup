set_languages("c99", "cxx14")
add_rules("mode.release", "mode.debug")
add_files("leetcode/*.cc")
add_packages("doctest")