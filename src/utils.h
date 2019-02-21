
String zero(String text, int cant) {
    while (text.length() < cant) {
        text = "0" + text;
    }

    return text;
}
