%function matd3pd = load_ringer_data(rootFileName,usePhotonCollection=false,getCellExtraInfo=false)
%
%Reads a D3PD generated containing the Offline Electron info including rings
% and returns it on matlab format.
%
%Input parameters are:
%rootFileName -> The D3PD file name (str). Wildcards (ex: path/*.root) are accepted.
%
%usePhotonCollection -> whether to read photon collection instead of electron collection.
%
%getCellExtraInfo -> whether to read cell Et, eta, phi information (this will make file much larger).


