def fn_str_process(str1, str2):
    str = str1 + str2
    listItems = []
    for s in str:
        listItems.append(s)

    dict = {}
    for item in listItems:
        dict[item] = 1

    return list(dict.keys())


print(fn_str_process("abc", "axyz"))
