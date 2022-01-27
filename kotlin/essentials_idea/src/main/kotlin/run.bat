call mkdir bin

echo ============================================================================
call echo Running types
echo ============================================================================
call kotlinc types.kt -include-runtime -d bin\types.jar && java -jar bin\types.jar

echo ============================================================================
call echo Running strings
echo ============================================================================
call kotlinc strings.kt -include-runtime -d bin\strings.jar && java -jar bin\strings.jar

echo ============================================================================
call echo Running control_flow
echo ============================================================================
call kotlinc control_flow.kt -include-runtime -d bin\control_flow.jar && java -jar bin\control_flow.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc collections_sequences.kt -include-runtime -d bin\collections_sequences.jar && java -jar bin\collections_sequences.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc io_files.kt -include-runtime -d bin\io_files.jar && java -jar bin\io_files.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc functions.kt -include-runtime -d bin\functions.jar && java -jar bin\functions.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc classes.kt -include-runtime -d bin\classes.jar && java -jar bin\classes.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc interfaces.kt -include-runtime -d bin\interfaces.jar && java -jar bin\interfaces.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc challenge.kt -include-runtime -d bin\challenge.jar && java -jar bin\challenge.jar

echo ============================================================================
call echo Running collections_sequences
echo ============================================================================
call kotlinc coroutines.kt -Xbuild-file=build.xml -include-runtime -d bin\coroutines.jar && java -jar bin\coroutines.jar

echo ============================================================================
call echo Done!
echo ============================================================================
