#inspired by itm4n script: https://itm4n.github.io/dll-proxying/

print("Name of the original DLL to hijack (without extension): ")
dllName = str(input())
dllRenamed = "_%s" %dllName

print("\nName of the HTML file exported from DLL Export Viewer (with extension): ")
exportedHTML = str(input())

f = open(exportedHTML)
page = f.readlines()
f.close()

f = open("functions.def", "w")
f.write("EXPORTS\n")

for line in page:
     if line.startswith("<tr>"):
        cols = line.replace("<tr>", "").split("<td bgcolor=#FFFFFF nowrap>")
        function_name = cols[1]
        ordinal = cols[4].split(' ')[0]
        f.write("%s=%s.%s @%s\n" % (function_name, dllRenamed, function_name, ordinal))

f.close()

print("\nfunctions.def has been created successfully!")
print("\nNote: the original DLL to hijack MUST be ranamed in: %s.dll" %dllRenamed)

input() # prevent shell auto-closing