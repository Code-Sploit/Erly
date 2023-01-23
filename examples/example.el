%import "std"
// maybe add an int after the brackets
// it will be easier to parse than fun int

fun main(int argc, char** argv) int {
    ;; multi line coment ;;
    ; inline comment
    
    print("Hello, World")

    int variable = 0
    str variable1 = "Hello"
    str* variable2 = {"Hello", "World"}

    if |variable == 0| {}

    for |int i = 0, i < 10, i++|
    {

    }

    loop {}

    while |variable != 1| {}

    match variable1 {
        "Hello" -> {},  // variable1 == "Hello"
        "Hello2" -> {}, // variable1 == "Hello2"
        _ -> {}         // else
    }

    return 0
}
