def clean_data(list):
    new_list = []
    for x in list:
        if type(x) is int or type(x) is float:
            new_list.append(x)
    return new_list

test = [12, "hello", 34.5, "python",60]
print(clean_data(test))