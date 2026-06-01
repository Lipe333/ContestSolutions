// ==UserScript==
// @name         Placar Bonito no Codeforces
// @version      2025-08-15
// @description  Coloca mil funcionalidades no placar do Codeforces
// @author       Fernando K
// @match        https://codeforces.com/gym/*/standings
// @icon         https://www.google.com/s2/favicons?sz=64&domain=codeforces.com
// @grant        none
// @license      GPL-3.0-or-later; https://www.gnu.org/licenses/gpl-3.0.txt
// ==/UserScript==

(function() {
    'use strict';
    const style = document.createElement('style');
    document.head.appendChild(style);
    style.type = 'text/css';
    style.appendChild(document.createTextNode(`
      .table-balloon {
        width: 20px;
        margin: -4px 2px;
      }
      .standings td {
      	width: 80px !important;
        height: 48px !important;
      }
      .standings td:nth-child(1) {
        font-size: 16px;
        font-weight: bold;
			}
      .standings td:nth-child(3) {
        font-size: 16px;
        font-weight: bold;
			}
      .standings {
        font-size: 14px;
      }
    `));
    {
        const svg = document.createElement('svg');
        var parser = new DOMParser();
        var doc = parser.parseFromString( `<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!-- Created with Inkscape (http://www.inkscape.org/) -->
<svg:svg version="1.1" id="balloon" width="29.999998" height="39.999996" viewBox="0 0 29.999998 39.999999" sodipodi:docname="balloon.svg" inkscape:version="1.2.2 (b0a8486541, 2022-12-01)" xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape" xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd" xmlns:svg="http://www.w3.org/2000/svg">
  <svg:defs id="defs874"/>
  <sodipodi:namedview id="namedview872" pagecolor="#505050" bordercolor="#ffffff" borderopacity="1" inkscape:pageshadow="0" inkscape:pageopacity="0" inkscape:pagecheckerboard="1" showgrid="false" inkscape:zoom="4.9186512" inkscape:cx="24.60024" inkscape:cy="44.626055" inkscape:window-width="1920" inkscape:window-height="1012" inkscape:window-x="0" inkscape:window-y="0" inkscape:window-maximized="1" inkscape:current-layer="layer1" inkscape:showpageshadow="2" inkscape:deskcolor="#505050"/>
  <svg:g inkscape:groupmode="layer" id="layer1" inkscape:label="Image 1" style="display:inline" transform="translate(30.979957,5.207267)">
    <svg:path style="fill:currentColor;stroke:#000000;stroke-width:1px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1" d="m -29.919637,15.847037 c -1.275765,-4.960284 -1.059588,-16.76613609 8.395563,-19.6674503 9.455142,-2.9013145 15.7609761,1.762701 18.7308504,6.7618205 2.96988324,4.999119 0.5345054,13.7336418 -3.739728,18.0854108 -4.2742364,4.351773 -9.3484174,6.044046 -11.8021434,6.437009 0,0 -0.51726,1.041029 -1.594333,0.96905 0.320106,2.622532 0.0534,1.538237 0.557868,3.195666 -1.101138,0.15878 -0.943229,0.0661 -2.121607,0.03649 -0.457696,1.844678 -1.543352,2.822692 -2.920588,2.597697 -1.377238,-0.225014 -1.759219,-1.071281 -2.091859,-1.966945 -0.332638,-0.895664 -0.263681,-2.254951 -1.406782,-2.46445 -1.143106,-0.209476 -1.458071,1.501213 -2.025272,1.312815 -0.332546,-0.13543 -0.689285,-0.467192 -0.228005,-1.039427 0.461243,-0.572236 1.457956,-1.467951 2.332039,-1.341026 0.874083,0.126931 1.355462,0.625786 1.798958,1.501522 0.443485,0.875738 0.29054,2.194507 1.295268,2.612614 1.004756,0.418116 2.055227,0.383094 2.117569,-1.360056 l -1.059957,-0.429295 c 0,0 1.654275,-2.189494 1.959115,-3.034982 -0.727031,-0.55079 -0.759458,-1.319123 -0.759458,-1.319123 0,0 -6.161685,-5.927087 -7.437461,-10.887378 z" id="path993" sodipodi:nodetypes="zzzzcccczzzczzzzccccz"/>
  </svg:g>
</svg:svg>`, "image/svg+xml");
        document.head.appendChild(doc.documentElement);
    }

    {
        const svg = document.createElement('svg');
        var parser = new DOMParser();
        var doc = parser.parseFromString(`<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<svg height="29.5pt" viewBox="0 -10 30.80912 29.5" width="30.749735pt" version="1.1" id="svg1" sodipodi:docname="star.svg" inkscape:version="1.3.2 (091e20ef0f, 2023-11-25)" xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape" xmlns:sodipodi="http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd" xmlns="http://www.w3.org/2000/svg" xmlns:svg="http://www.w3.org/2000/svg">
  <path d="M 30.355353,1.2332253 C 30.158586,0.62457761 29.618738,0.19228551 28.980047,0.13472361 L 20.304403,-0.65303317 16.87382,-8.6826481 c -0.252953,-0.5884668 -0.829036,-0.9693883 -1.469103,-0.9693883 -0.640067,0 -1.21615,0.3809215 -1.469103,0.9707643 L 10.50503,-0.65303317 1.8280105,0.13472361 C 1.1904664,0.19366161 0.65199408,0.62457761 0.45408022,1.2332253 0.25616636,1.8418735 0.43894425,2.5094599 0.92123026,2.9302848 L 7.4789896,8.6814823 5.545259,17.199574 c -0.1414981,0.626307 0.1015942,1.273713 0.6212614,1.649359 0.2793272,0.201812 0.6061255,0.304553 0.9356767,0.304553 0.2841425,0 0.565992,-0.0766 0.8189454,-0.227956 l 7.4835745,-4.472669 7.480822,4.472669 c 0.547416,0.329322 1.237477,0.299279 1.755998,-0.0766 0.519896,-0.376793 0.762759,-1.024427 0.621262,-1.649359 L 23.329068,8.6814823 29.886827,2.9314314 c 0.482286,-0.4219715 0.66644,-1.0884113 0.468526,-1.6982061 z m 0,0" fill="#ffc107" id="star" style="fill:currentColor;stroke:#000000;stroke-width:0.751448;stroke-dasharray:none"/>
</svg>`, "image/svg+xml");
        document.head.appendChild(doc.documentElement);
    }

    const colorNamesToHtml = {
        'white': 'FFFFFF',
        'black': '000000',
        'red': 'FF0000',
        'maroon': '800000',
        'yellow': 'FFFF00',
        'green': '008000',
        'blue': '0000FF',
        'navy': '000080',
        'pink': 'FF00FF',
        'purple': '800080',
        'lime': '00FF00',
        'cyan': '00FFFF',
        'silver': 'C0C0C0',
        'orange': 'FF8000',
        'brown': 'A3794D'
    };

    function callback() {
        const [header, ...trs] = [...document.querySelector('.standings tbody').children];
        trs.forEach(tr => {
            const [rank, team, score, penalty, ...balloons] = [...tr.children];
            balloons.forEach((balloon, i) => {
              	const span = balloon.querySelector('span');
                const fails = +(span.innerText.replace('+', '') ?? "0");
              	if (span.classList.contains("cell-rejected") && fails == 0) { return; }
                if (span.classList.contains("cell-rejected")) {
                    // only fails
                    balloon.innerHTML = (-fails) + '/-';
                    return;
                }
                const timeNode = balloon.querySelector('span.cell-time');
                const [hours, minutes] = timeNode.innerText.split(':').map(Number);
                const viewBox = balloon.classList.contains('fb') ? '0 -10 30 30' : '-2 0 34 40';
                const imageName = balloon.classList.contains('fb') ? 'star' : 'balloon';
                balloon.innerHTML = '<svg class="table-balloon" viewBox="' + viewBox + '" color="#' + Object.values(colorNamesToHtml)[i] + '"><use href="#' + imageName + '"></use></svg>' + (fails+1) + '/' + (hours*60 + minutes);
            })
        });
    }

    setInterval(callback, 1000);
})();
