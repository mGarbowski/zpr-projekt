#!/bin/bash

# Variables
OUTPUT_DIR="test_coverage_html"       # Directory for HTML output
SRC_COV="src_base_cov.info"           # Initial source coverage file
APP_TEST_COV="app_test.info"          # Application test coverage file
TOTAL_COV="app_total.info"            # Combined total coverage file




cmake -E remove -f coverage.info
cmake -E remove_directory "$OUTPUT_DIR"

# Step 1: Generate initial coverage data
lcov -c -i -d . -o "$SRC_COV"

# Step 2: Generate HTML report for base coverage
genhtml "$SRC_COV" --output-directory "$OUTPUT_DIR"

# Step 3: Collect coverage data after tests
lcov -c -d . -o "$APP_TEST_COV"

# Step 4: Combine initial and test coverage data
lcov -a "$SRC_COV" -a "$APP_TEST_COV" -o "$TOTAL_COV"

lcov --remove "$TOTAL_COV" "*/build/_deps/*" "*/usr/include/c++/11/*" "*/build/_deps/googletest-src/*" --output-file "$TOTAL_COV"

# Step 5: Generate final HTML coverage report
genhtml "$TOTAL_COV" --output-directory "$OUTPUT_DIR"

# Script end
echo "Coverage reports generated in $OUTPUT_DIR."
