// Externe Links (andere Domain als die Kursseite selbst) bekommen
// automatisch target="_blank" + rel="noopener", damit sie sich in einem
// neuen Tab oeffnen. Interne Links (relative Pfade, Anker) sind davon nicht
// betroffen - sie navigieren weiterhin ganz normal in derselben Seite.
document.addEventListener("DOMContentLoaded", function () {
  var host = window.location.hostname;

  document.querySelectorAll('a[href^="http"]').forEach(function (link) {
    try {
      var url = new URL(link.href);
      if (url.hostname !== host) {
        link.setAttribute("target", "_blank");
        link.setAttribute("rel", "noopener");
      }
    } catch (e) {
      // Ungueltige URL - Link unangetastet lassen.
    }
  });
});
