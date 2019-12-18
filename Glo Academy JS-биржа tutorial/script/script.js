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


    const orders = []; //массив заказов const чтобы мы не переприсваивали значение

    const renderOrders = (() => {
        ordersTable.textContent = ``;//обнуление заказов, чтобы постоянно не накапливалист строки таблицы, т.е. каждый раз переписываем ее заново с помощью inner.HTML

        orders.forEach((order, i) => {

            // работа с таблицей из фрилансера

            ordersTable.innerHTML += `
<tr class="order" data-number-order="${i}">
					<td>${i+1}</td> 
					<td>${order.title}</td>
					<td class="${order.currency}"></td>
					<td>${order.deadline}</td>
</tr>`
// data-number-order это датаатрибут
//первый td значение в первом столбце(номер заказа)
// второй это заголовок из задания  
//третий валюта из задания(в классе, чтобы выводить значение в поле картинкой?- da) не использовать обратные кавычки
// четвертый это срок выполнения
        });
    });

    const openModal = (numberOrder) => {
       const order = orders[numberOrder];
       const modal = order.active ? modalOrderActive : modalOrder;
       
       const firstNameBlock = document.querySelector(`.firstName`),
       titleBlock = document.querySelector(`.modal-title`),
       emailBlock = document.querySelector(`.email`),
       descriptionBlock = document.querySelector(`.description`),
       deadlineBlock = document.querySelector(`.deadline`),
       currencyBlock = document.querySelector(`.currency_img`),
       countBlock = document.querySelector(`.count`),
       phoneBlock = document.querySelector(`.phone`);
       

       titleBlock.textContent = order.title;
       firstNameBlock.textContent = order.firstName;
       emailBlock.textContent = order.email;
       descriptionBlock.textContent = order.description;
       deadlineBlock.textContent = order.deadline;
       currencyBlock.innerHTML = `<span class="img__radio img__radio_${order.currency}"></span>`;
       countBlock.textContent = order.amount;
       if (order.phone) phoneBlock.textContent = order.phone;
       
       modal.style.display = `block`;//выводим на дисплей нашу модалку в зависимости от того, активный заказ или нет

       closeBlock = document.getElementsByClassName(`close text-white`);
       console.log(' closeBlock: ',  closeBlock);
       closeBlock[0].addEventListener(`click`, () => modal.style.display = `none`)

    }

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


        orders.push(obj); //добавляем заказы в массив заказов
        console.log('obj: ', orders);

    });


})