document.addEventListener(`DOMContentLoaded`, () => {
    `use strict`;
    const customer = document.getElementById(`customer`);
    const freelancer = document.getElementById(`freelancer`)
    const blockCustomer = document.getElementById(`block-customer`);
    const blockFreelance = document.getElementById(`block-freelancer`);
    const blockChoice = document.getElementById(`block-choice`);
    const btnExit = document.getElementById(`btn-exit`);
    const formCustomer = document.getElementById(`form-customer`);
    const ordersTable = document.getElementById(`orders`); //получили таблицу из фрилансера
    const modalOrder = document.getElementById(`order_read`); //получаем html если хотим получить только начатый заказ
    const modalOrderActive = document.getElementById(`order_active`);// получаем html данные если хотим получить открытый заказ


    let orders = JSON.parse(localStorage.getItem(`freeOrders`)) || []; //массив заказов проверяем на наличие заказов в локалсторадже, если их нет, то пустой массив

    const toStorage = () => {
        localStorage.setItem(`freeOrders`, JSON.stringify(orders));
    };

    const todayDay = () => {
        let today = new Date();
        today = `${today.getFullYear()}-${today.getMonth()+1}-${today.getDate()}`;
        return today
    };

    function declOfNum(n, titles) {
        return titles[n%10==1 && n%100!=11 ? 0 : n%10>=2 && n%10<=4 && (n%100<10 || n%100>=20) ? 1 : 2];
      };

    const calcDeadline = (date) => {
        let today = new Date();
        let deadline = new Date(date);
        let remaining = Math.ceil(Math.abs(deadline.getTime() - today.getTime()) / (1000 * 3600 * 24));
        
        if (remaining < 2) {
            remaining = Math.ceil(Math.abs(deadline.getTime() - today.getTime()) / (1000 * 3600));
            return ( `${remaining} ${declOfNum(remaining, [`час`, `часа`, `часов`])}`);
        }else{
        return ( `${remaining} ${declOfNum(remaining, [`день`, `дня`, `дней`])}`);
    }};

    const renderOrders = (() => {
        ordersTable.textContent = ``;//обнуление заказов, чтобы постоянно не накапливалист строки таблицы, т.е. каждый раз переписываем ее заново с помощью inner.HTML

        orders.forEach((order, i) => {

            // работа с таблицей из фрилансера

            ordersTable.innerHTML += `
<tr class="order ${order.active ? `taken` : `` } " data-number-order="${i}">
					<td>${i+1}</td> 
					<td>${order.title}</td>
					<td class="${order.currency}"></td>
					<td>${calcDeadline(order.deadline)}</td>
</tr>`
// обрати внимание, что в шаблонных строках обратные кавычки
// data-number-order это датаатрибут
//первый td значение в первом столбце(номер заказа)
// второй это заголовок из задания  
//третий валюта из задания(в классе, чтобы выводить значение в поле картинкой?- da) не использовать обратные кавычки
// четвертый это срок выполнения
        });
    });


    const handlerModal = (event) => {
        const target = event.target;

        const modal = target.closest(`.order-modal`);

        const order = orders[modal.id];

        const baseAction = () => {
        modal.style.display = `none`;
        toStorage();
        renderOrders();
        };

        if (target.closest(`.close `) || (target == modal)) {
            modal.style.display = `none`;
        };

        if (target.classList.contains(`get-order`)) {
            order.active = true;
            baseAction();
        };

        if (target.id === `capitulation`) {
            order.active = false;//если отказываемся от заказа то опять делаем его неактивным
            baseAction();
        };

        if (target.id === `ready`) {
            
            orders.splice(orders.indexOf(order), 1);//какой элемент по индексу удалить, сколько удалить
            baseAction();
        };

    };


    const openModal = (numberOrder) => {
       
       const order = orders[numberOrder];
       
       const { title, firstName, email, phone, description,
         amount, currency, deadline, active = false } = order;//деструктивное присваивание, {какие свойства} = откуда, если из массива то []s
       // active = false это свойство по умолчанию
         let modal = order.active ? modalOrderActive : modalOrder;

       
       

       const firstNameBlock = modal.querySelector(`.firstName`),
       titleBlock = modal.querySelector(`.modal-title`),
       emailBlock = modal.querySelector(`.email`),
       descriptionBlock = modal.querySelector(`.description`),
       deadlineBlock = modal.querySelector(`.deadline`),
       currencyBlock = modal.querySelector(`.currency_img`),
       countBlock = modal.querySelector(`.count`),
       phoneBlock = modal.querySelector(`.phone`);
       

       modal.id = numberOrder;//индекс заказа
       titleBlock.textContent = title;
       firstNameBlock.textContent = firstName;
       emailBlock.textContent = email;
       emailBlock.href = `mailto: ` + email;//запись емейла в чреф
       descriptionBlock.textContent = description;
       deadlineBlock.textContent = calcDeadline(deadline);
       //currencyBlock.innerHTML = `<span class="img__radio img__radio_${order.currency}"></span>`;//вставка картинки с методом оплаты или алтернативно
       currencyBlock.className = `currency_img`; //по умолчанию перед добавление нового класса сбрасываем его в currency_img
       currencyBlock.classList.add(currency);//альтернативный   метод
       countBlock.textContent = amount;
       if (order.phone && phoneBlock) phoneBlock.href = `tel: ` + order.phone;//tel: запускает либо скайп либо телефон и тп
    //    console.log('firstNameBlock: ', firstNameBlock);


       modal.style.display = `flex`;//выводим на дисплей нашу модалку в зависимости от того, активный заказ или нет

       modal.addEventListener(`click`, handlerModal);//клик в любое место в модальном окне



    };

    ordersTable.addEventListener(`click`, event => { //обработчик события вешаем сразу на всю таблицу 
        const target = event.target;// при клике на определенную ячейку таблицы выдает нам td?
        
        const targetOrder = target.closest(`.order`); // чтобы при тыке в любое место строки выводилось значение этой строки
        if (targetOrder) {
            openModal(targetOrder.dataset.numberOrder);//функция, чтобы при клике на строку таблицы выдавало модальное окно, посылаем датаатрибут(в нашем случае номер заказа)
        }

        //console.log('targetOrder: ', orders[targetOrder.dataset.numberOrder]);//orders[targetOrder.dataset.numberOrder обратились ко всем заказам orders и вытащили именно этот заказ 
        // поднимается выше по цепочке вложенностей до поиска того, что стоит в скобке
        // в таргетордере есть датаатрибуты и от взял их датасетом и посмотрел
    });

    customer.addEventListener(`click`, () => {
        blockChoice.style.display = `none`;
        blockCustomer.style.display = `block`;
        btnExit.style.display = `block`;
        document.getElementById(`deadline`).value = `${todayDay()}`;// значение по умолчанию для срока выполнения
        document.getElementById(`deadline`).min = `${todayDay()}`; // срок выполнения не раньше сегодня
    });

    freelancer.addEventListener(`click`, () => {
        blockChoice.style.display = `none`;
        renderOrders(); //во время клика по кнопке "фрилансер" вызываем функцию  renderOrders
        blockFreelance.style.display = `block`;
        btnExit.style.display = `block`;
    });
    btnExit.addEventListener(`click`, () => {
        btnExit.style.display = `none`;
        blockFreelance.style.display = `none`;
        blockCustomer.style.display = `none`;
        blockChoice.style.display = `block`;
    })

    formCustomer.addEventListener(`submit`, (event) => {

        event.preventDefault(); //запрещает перезагрузку страницы

        const obj = {};

        // эта штука тоже работает!!!
        // for (const elem of formCustomer.elements){//перебираем элементы с тегами импут, чтобы взять изнутри них информацию
        //     if ( (elem.tagName === `INPUT` && elem.type !== `radio`)  ||
        //     (elem.type === `radio` && elem.checked) ||
        //     elem.tagName === `TEXTAREA`){ // убрали радиокнопки(выбор дошика и шаурмы и оставили только то, что выбрали)

        //         obj[elem.name] = elem.value;

        //         if (elem.type !== `radio`){
        //             elem.value = ``;
        //         }

        //     }

        // }


        // перебор элементов методом forEach
        // [...formCustomer.elements].forEach(elem => {
        //     if ( (elem.tagName === `INPUT` && elem.type !== `radio`)  ||
        //     (elem.type === `radio` && elem.checked) ||
        //     elem.tagName === `TEXTAREA`){ // убрали радиокнопки(выбор дошика и шаурмы и оставили только то, что выбрали)

        //         obj[elem.name] = elem.value;

        //         if (elem.type !== `radio`){
        //             elem.value = ``;
        //         }

        //     }
        // }); //[...] разбили объект в массив


        // с помощью arr.filter
        const elements = [...formCustomer.elements].filter(elem => ((elem.tagName === `INPUT` && elem.type !== `radio`) ||
            (elem.type === `radio` && elem.checked) ||
            (elem.tagName === `TEXTAREA`)));
        elements.forEach(elem => {
            obj[elem.name] = elem.value;

        });
        
        formCustomer.reset(); // сбрасываем значение в форме до значений по умолчанию (то, что в value  в формах инпутов)
        document.getElementById(`deadline`).value = `${todayDay()}`;

        orders.push(obj); //добавляем заказы в массив заказов
        if (orders.length > 1) {
        let byDate = orders.slice(0);
        byDate.sort((a,b) => {let first = new Date(a.deadline);
        let second = new Date(b.deadline);
        return (first.getTime() - second.getTime());
    });
    orders = byDate;
        };

        toStorage();//добавление данных в локал сторедж

    });


})