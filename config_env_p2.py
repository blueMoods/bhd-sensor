import os

esp_idf_path = os.getenv("IDF_PATH")
bhd_sensor_path = os.getenv("BHD_SENSOR_PATH")
project_mk_fname = "/make/project.mk"


print("IDF_PATH: {}\n".format(esp_idf_path))
print("BHD_SENSOR_PATH: {}\n".format(bhd_sensor_path))

os.chdir(bhd_sensor_path)
print("Change directory to: {}".format(os.getcwd()))
os.mkdir("make")


with open(esp_idf_path + project_mk_fname, "rt") as orig_f:
    with open(bhd_sensor_path  + project_mk_fname, "wt") as f:
        for tline in orig_f:
            if tline.find("$(IDF_PATH)/components") != -1:
                print >> f, tline.rstrip() + " $(BHD_SENSOR_PATH)/components"
            else:
                print >> f, tline,
print("config end\n")
