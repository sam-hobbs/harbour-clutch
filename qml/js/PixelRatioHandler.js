/*
 * Hack to fix wrong device Pixel Ratio reported by Webview, as used by WebPirate and WebCat:
 * https://github.com/llelectronics/webcat/blob/a769a338d186d901a13f9a5e30580026e0baf3c5/qml/pages/helper/devicePixelRatioHack.js
 * https://github.com/Dax89/harbour-webpirate/blob/d588aa1a98715add42cca8b372d31d4634a71a6b/harbour-webpirate/qml/js/webview/lib/PixelRatioHandler.js
 */

// self executing function
(function() {
    // code in here will execute right away
    // since the () at the end executes this (function(){})

    var viewport = document.querySelector("meta[name='viewport']");

    if(screen.width <= 540) /* Jolla devicePixelRatio: 1.5 */
        viewport.content = "width=device-width/1.5, initial-scale=1.5";
    else if(screen.width > 540 && screen.width <= 768) /* Nexus 4 devicePixelRatio: 2.0 */
        viewport.content = "width=device-width/2.0, initial-scale=2.0";
    else if (screen.width > 768) /* Nexus 5 devicePixelRatio: 3.0 */
        viewport.content = "width=device-width/3.0, initial-scale=3.0";

})();
