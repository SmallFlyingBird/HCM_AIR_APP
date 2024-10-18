
# Build Tools Configuration

# Build Tool GHS Path (manual Set)
GHS_DIR = D:/ghs/comp_202114


# Build Source Configuration

# Build Project (manual Set)
# EPT		(0001)Electric Performance Test
# G636		(0002)G636
# HS11		(0003)HS11
# FX11		(0004)FX11
# ...
# about Project Name
BUILD_PROJECT = EPT

# Build ParaMgr.c Select (manual Set)
# copy ../Base/Parameter/stock/$(BUILD_PROJECT)/$(BUILD_PARAMGR).c to ../Base/Parameter/0000_Default/ParaMgr.c
# space, don't copy
#
# about Project Configre
BUILD_PARAMGR = GEN2_V12.1

# Build Left/Right (manual Set)
#     0: Left
# not 0: Right
BUILD_LE0RI = 0
