
(cl:in-package :asdf)

(defsystem "htbot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Command" :depends-on ("_package_Command"))
    (:file "_package_Command" :depends-on ("_package"))
    (:file "clear" :depends-on ("_package_clear"))
    (:file "_package_clear" :depends-on ("_package"))
    (:file "debug" :depends-on ("_package_debug"))
    (:file "_package_debug" :depends-on ("_package"))
    (:file "go" :depends-on ("_package_go"))
    (:file "_package_go" :depends-on ("_package"))
    (:file "lumstatus" :depends-on ("_package_lumstatus"))
    (:file "_package_lumstatus" :depends-on ("_package"))
    (:file "move" :depends-on ("_package_move"))
    (:file "_package_move" :depends-on ("_package"))
    (:file "move_status" :depends-on ("_package_move_status"))
    (:file "_package_move_status" :depends-on ("_package"))
    (:file "odom" :depends-on ("_package_odom"))
    (:file "_package_odom" :depends-on ("_package"))
    (:file "queue" :depends-on ("_package_queue"))
    (:file "_package_queue" :depends-on ("_package"))
    (:file "scanCmd" :depends-on ("_package_scanCmd"))
    (:file "_package_scanCmd" :depends-on ("_package"))
    (:file "sound" :depends-on ("_package_sound"))
    (:file "_package_sound" :depends-on ("_package"))
    (:file "stat" :depends-on ("_package_stat"))
    (:file "_package_stat" :depends-on ("_package"))
    (:file "stat_speed" :depends-on ("_package_stat_speed"))
    (:file "_package_stat_speed" :depends-on ("_package"))
    (:file "status" :depends-on ("_package_status"))
    (:file "_package_status" :depends-on ("_package"))
    (:file "velstat" :depends-on ("_package_velstat"))
    (:file "_package_velstat" :depends-on ("_package"))
  ))