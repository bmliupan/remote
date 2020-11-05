#!/usr/bin/python3

# -*- coding: UTF-8 -*-

strlist = [] #声明一个空的列表
strlist.append('IO_P1UPRE_ADDR')
strlist.append('IO_P2UPRE_ADDR')
strlist.append('IO_P1TSM_ADDR')
strlist.append('IO_P2TSM_ADDR')
strlist.append('IO_P1WAKE_ADDR')
strlist.append('IO_P2WAKE_ADDR')
strlist.append('IO_P1MODE_ADDR')
strlist.append('IO_P2MODE_ADDR')
strlist.append('IO_P1DATA_ADDR')
strlist.append('IO_P2DATA_ADDR')
strlist.append('KEY_START_ADDR')
strlist.append('KEY_P2MODE_ADDR')
strlist.append('KEY_P1MODE_ADDR')
strlist.append('KEY_P2DATA_ADDR')
strlist.append('KEY_P1DATA_ADDR')
strlist.append('CHECK_IO_ADDR')
strlist.append('LIGHT_ON_M_ADDR')
strlist.append('LIGHT_ON_D_ADDR')
strlist.append('LIGHT_OFF_M_ADDR')
strlist.append('LIGHT_OFF_D_ADDR')
strlist.append('LEARN_KEY_PRESS_ADDR')
strlist.append('LEARN_KEY_FREE_ADDR')
strlist.append('LEARN_WAIT_IR_ADDR')
strlist.append('KEY_DATA_ADDR')
strlist.append('TV_USER_FORMAT_ADDR')
strlist.append('TV_USER_CODE1_ADDR')
strlist.append('TV_USER_CODE2_ADDR')
strlist.append('TV_USER_CODE3_ADDR')
strlist.append('TV_USER_CODE4_ADDR')
strlist.append('STB_USER_FORMAT_ADDR')
strlist.append('STB_USER_CODE1_ADDR')
strlist.append('STB_USER_CODE2_ADDR')
strlist.append('STB_USER_CODE3_ADDR')
strlist.append('STB_USER_CODE4_ADDR')
strlist.append('SET_KEY_ADDR1')
strlist.append('SET_KEY_ADDR2')
strlist.append('SET_KEY_ADDR3')
strlist.append('SET_KEY_ADDR4')
strlist.append('LEARN_KEY_ADDR')
strlist.append('SET_OUTPUT_ADDRS1')
strlist.append('SET_OUTPUT_ADDRS2')
strlist.append('SET_INPUT_SADDR')
strlist.append('SET_OUTPUT_ADDR1')
strlist.append('SET_OUTPUT_ADDR2')
strlist.append('SET_OUTPUT_ADDR3')
strlist.append('SET_OUTPUT_ADDR4')
strlist.append('SET_INPUT_ADDR')


listFile = open('../../IC_work/LearnRoutineWithLibrary/LearnRoutineWithLibrary.LST','r',encoding='gbk')
mydict = {}
for index in range(len(strlist)):
    print(index)
    for lines in listFile.readlines():
        if strlist[index] in lines:
            print("find it ***********")
            print(lines)
            print(lines[10:14])
            mydict[strlist[index]] = lines[10:14]
            listFile.seek(0)
            break

#print(mydict)     #打印字典数据
listFile.close()

for key in mydict.keys():
    saveFile = open('./ltFileParameter.h','r',encoding='utf-8')
    fileData = ""
    for lines in saveFile.readlines():
        if key in lines:
            #print("find key success!")
            #print(lines)
            newLine = "#define    "+str("{:<40}".format(key))+"100+4*0x"+str(mydict[key])+"\n"
            print("修改后的字串：",newLine)
            fileData+=newLine
        else:
            fileData+=lines
    #print(fileData)
    saveFile = open('./ltFileParameter.h','w',encoding='utf-8')
    saveFile.write(fileData)
    saveFile.close()



