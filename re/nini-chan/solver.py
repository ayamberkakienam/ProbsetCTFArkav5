import subprocess
import string

def get_count(flag):
    PINTOOLS_PATH = "/opt/ctf/pintools/pin"
    INSCOUNT_PATH = "/opt/ctf/pintools/source/tools/ManualExamples/obj-intel64/inscount0.so"
    NINICHAN_PATH = "./nini-chan"
    code = subprocess.call([
        PINTOOLS_PATH,
        "-t",
        INSCOUNT_PATH,
        "--",
        NINICHAN_PATH,
        flag
    ])

    # flag found
    if code == 0:
        print("Arkav5{%s}" % flag)
        quit()

    count = open("inscount.out", "r").read()[6:]
    return int(count)

charset = "_" + string.ascii_letters + string.digits
flag = ["?"] * 10
for i in range(len(flag)):
    max_count = 0
    max_c = None
    for c in charset:
        flag[i] = c
        count = min([get_count("".join(flag)) for _ in range(2)])
        print(c, count)
        if count > max_count:
            max_count = count
            max_c = c
    flag[i] = max_c
    print("".join(flag))
