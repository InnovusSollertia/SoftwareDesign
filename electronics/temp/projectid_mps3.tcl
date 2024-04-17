## Recorded on 2024-04-16T18:37:39
#grid both -size [list 0.1 0.5 0.1] -style lines 5 -unit INCHES -notifyFromSch
#refreshDesignExplorer
cpb::launchSelectorDialog "createNewProject"
newProject {projectid_mps3 projectid_mps3 {D:/Projects/ProjectScience/electronics} sch composite -unified }
refreshDesignExplorer
cpSdaLckT::postCreateLock {D:/Projects/ProjectScience/electronics/projectid_mps3.cpm} 1
refreshDesignData
cps::setComponentExplorerWidgetVisibilityOff
selectItem {@worklib.projectid_mps3(tbl_1):Page(1)} SCH PAGE activatetab
selectItem {@worklib.projectid_mps3(tbl_1):Page(1)} SCH PAGE activatetab
set hybridHandle2 [cpCommon::dockedHybridInit {Details} {CP_ADD_COMPONENT_SEARCH_DETAILS_DOCK} {}]; cps::addDock $hybridHandle2 $::cps::DA_RIGHT $::cps::WO_VERT true
set hybridHandle1 [cpCommon::dockedHybridInit {Unified Search} {CP_ADD_COMPONENT_SEARCH_DOCK} {}]; cps::addDock $hybridHandle1 $::cps::DA_BOTTOM $::cps::WO_HORIZ true
grid both -size [list 0.1 0.5 0.1] -style lines 5 -unit INCHES -notifyFromSch
cpSdaLckT::lockProject {D:/Projects/ProjectScience/electronics/projectid_mps3.cpm} 1
cps::isProjectOpen
refreshDesignExplorer  {Livebom}
cpSchT::setUnifiedSearchLoginStatus {false}
cpbf::getMasterID
cpSchT::unifiedSearchOpenDetailsPanel
cpSchT::unifiedSearchOpenDetailsPanel
cps::refreshHierarchyExplorer {LDAX_Libraries_Node}
cps::refreshHierarchyExplorer {LDAX_Templates_Node}
cpSchT::unifiedSearchOpenDetailsPanel
cpb::getDesignJsonPath {projectid_mps3} {true}
cpSchT::setUnifiedSearchLoginStatus {false}
cpSchT::unifiedSearchOpenDetailsPanel
cpSchT::unifiedSearchOpenDetailsPanel
cpSchT::unifiedSearchOpenDetailsPanel
cpSchT::unifiedSearchOpenDetailsPanel
cpSchT::unifiedSearchOpenDetailsPanel
#updateComponent addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}] -cmd {addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]}
#cps::contextCall SCH PAGE {addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]}
#addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]
#cpSchT::setDimmingBrowser 1
#cpSchT::setDimmingBrowser 0
updateComponent addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}] -cmd {addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]}
cps::contextCall SCH PAGE {addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]}
addComponent {standard} {cadence#20b#20size#20page} {sym_1} {CADENCE#20B#20SIZE#20PAGE} -n 1 -key [list {NAME=cadence b size page=0} {CDS_LIBRARY_ID=01FEBSNP10HQYP1YZ8G3QE0563=0}]
cpSchT::setDimmingBrowser 0
cpSchT::setDimmingBrowser 1
#setReplaceBrowserDlgVisibiltiy 0
cps::cleanLibraryValidationWindow
cps::setDockedWidgetVisibilityOff {CP_SYM_ERROR_VIOLATION_DOCK}
cpSymT::destroyValidationWidget
#cppt::cleanWidgetManagerStores
cppt::cleanWidgetManagerStores
