(ns service.handler
  (:use compojure.core)
  (:require [compojure.handler :as handler]
            [compojure.route :as route]
            [clojure.string :as s]
            ))

(defn handle-reverse [text]
    (s/reverse text))

(defn handle-reverse2 [params]
    (str params))

(defn handle-reverse3 [{text "text"}]
    ; handle nil!
    ; (s/reverse text))
    (some-> text s/reverse ))

(defn handle-reverse4 [{text "text"}]
    (let [join #(s/join " " %)]
        (some-> text (s/split #"\s+") reverse join)))

(defn handle-reverse4 [{text "text"}]
    (let [join #(s/join " " %)]
        (some-> text (s/split #"\s+") reverse join)))

(defn handle-add [a b]
    (str (+ a b)))

; (defn handle-calc [a b]
;     (str (+ a b)))

(defn add[] "+")

(let [string->double #(-> % read-string double)]

(defn handle-calc [operation arg1 arg2]

    (str "you entered " arg1 " " operation " " arg2 ": "
      ; (let [op (symbol operation)
      ;       a (string->double arg1)
      ;       b (string->double arg2)]
      ;   (eval `(~op ~a ~b))))

        (eval `(
          (symbol operation)
          (string->double arg1)
          (string->double arg2))))

    (defroutes app-routes
      (GET "/" [] "Hello World asdf")
      (GET "/reverse/:text" [text] (handle-reverse text))
      (GET "/reverse2/" {params :query-params} (handle-reverse2 params))
      (GET "/reverse3/" {params :query-params} (handle-reverse3 params))
      (GET "/reverse4/" {params :query-params} (handle-reverse4 params))
      (GET "/add/:a/:b/" [a b] (handle-add (string->double a) (string->double b)))
      (GET "/calculate/:operation/:arg1/:arg2" [operation arg1 arg2] (handle-calc operation arg1 arg2))
      (route/resources "/")
      (route/not-found "Not Found")))

; (fn [x] (+ x 1))
; is the same as
; #(+ % 1)


; #(+ %1 %2 )
; %1 is first, %2 is rest

; #(apply + %&)

(def app
  (handler/site app-routes))
